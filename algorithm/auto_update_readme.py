# -*- coding: utf-8 -*-

import os
import re
import sys
from collections import OrderedDict

README_FILE = "README.md"
SRC_DIRS = ["cpp", "python"]


def check_running_dir():
    if any([_dir not in os.listdir(os.path.curdir) for _dir in SRC_DIRS]):
        raise RuntimeError("Must running in the root directory")


class ProblemItem(object):
    serial = None  # number
    title = None
    url = None
    solutions = None  # [(language), (No), (path)]
    difficulty = None  # ["Easy", "Medium", "Hard"]

    def __init__(self):
        self.solutions = []

    def from_cache_format(self, line):
        _, serial, title_url, solutions, difficulty, _ = line.split("|")
        self.serial = serial
        self.title, self.url = re.findall(re.compile("\[(.*)\]\((.*)\)"), title_url)[0]
        self.solutions = re.findall(re.compile("\[([a-zA-Z+]*?)-?([IVX]*?)\]\((.*?)\)"), solutions)
        self.solutions = [tuple(item) for item in self.solutions]
        self.difficulty = difficulty

    def dump(self):
        return "|" + "|".join([
            self.serial,
            "[{0}]({1})".format(self.title, self.url),
            ",".join(["[{0}{1}]({2})".format(item[0],
                                             "-" + item[1] if item[1] else item[1],
                                             item[2]) for item in self.solutions]),
            self.difficulty
        ]) + "|\n"


class BaseExtractor(object):
    sub_dir = None
    file_postfix = None
    solution_type = None
    path_base = None
    comment_prefix = None

    def __init__(self):
        self.path = os.path.join(os.path.curdir, self.sub_dir)
        self.entry_list = []

    def traverse_entry(self):
        for _dir in os.listdir(self.path):
            problem_item = self.parse_item(_dir)
            self.entry_list.append(problem_item)

    def parse_item(self, directory):
        item = ProblemItem()
        for _file in os.listdir(os.path.join(self.path, directory)):
            header = {}
            with open(os.path.join(self.path, directory, _file), "r") as f:
                header["Path"] = self.path_base.format(directory, _file)
                try:
                    header["Method"] = re.findall("\w-(\w+).{}".format(self.file_postfix), _file)[0]
                except IndexError:
                    header["Method"] = ""
                for _line in f.readlines():
                    if not _line.startswith(self.comment_prefix):
                        break
                    key, value = _line[3:].split(":", 1)
                    header[key.strip()] = value.strip()
            item.serial = item.serial or header["Number"]
            item.title = item.title or header["Title"]
            item.url = item.url or header["Source"]
            item.solutions.append((self.solution_type, header["Method"], header["Path"]))
            item.difficulty = item.difficulty or header["Difficulty"]
        return item


class CppExtractor(BaseExtractor):
    """
    // Number     : 56
    // Title      : Merge Intervals
    // Source     : https://leetcode.com/problems/merge-intervals/description/
    // Difficulty : Medium
    // Author     : William
    // Date       : 2017-12-06
    """
    file_postfix = "cpp"
    sub_dir = "cpp"
    solution_type = "c++"
    path_base = "./algorithm/cpp/{}/{}"
    comment_prefix = "// "

    def __init__(self):
        super(CppExtractor, self).__init__()


class PythonExtractor(BaseExtractor):
    """
    #  Number     : 56
    #  Title      : Merge Intervals
    #  Source     : https://leetcode.com/problems/merge-intervals/description/
    #  Difficulty : Medium
    #  Author     : William
    #  Date       : 2017-12-06
    """
    sub_dir = "python"
    file_postfix = "py"
    solution_type = "py"
    path_base = "./algorithm/python/{}/{}"
    comment_prefix = "#  "

    def __init__(self):
        super(PythonExtractor, self).__init__()


class ReadmeDoc(object):
    description = "LeetCode Algorithm\n========\n\n"
    header = "| # | Title | Solution | Difficulty |\n"
    boundary = "|---| ----- | -------- | ---------- |\n"
    meta = "".join([description, header, boundary])

    def __init__(self, filename):
        self.filename = os.path.join(os.path.pardir, filename)
        self.entry_dict = OrderedDict()

    def loads(self):
        with open(self.filename, mode="r") as f:
            begin_flag = False
            for line in f.readlines():
                if line == self.boundary:
                    begin_flag = True
                    continue
                if begin_flag and line:
                    entry = ProblemItem()
                    entry.from_cache_format(line)
                    # todo: optimize for not read exist file
                    # self.entry_dict[entry.serial] = entry

    def merge(self, entry_iter):
        for entry in entry_iter:
            if entry.serial not in self.entry_dict:
                self.entry_dict[entry.serial] = entry
            else:
                # todo: optimize for not read exist file
                self.entry_dict[entry.serial].solutions = list(set(entry.solutions) |
                                                               set(self.entry_dict[entry.serial].solutions))
            # sort the solution by language and method version
            self.entry_dict[entry.serial].solutions = sorted(self.entry_dict[entry.serial].solutions,
                                                             key=lambda x: x[0])

    def dumps(self):
        with open(self.filename, mode="w") as f:
            f.write(self.meta)
            self.entry_dict = OrderedDict(sorted(self.entry_dict.items(), key=lambda x: int(x[0])))
            for entry in self.entry_dict.values():
                f.write(entry.dump())


def main():
    check_running_dir()

    doc = ReadmeDoc(README_FILE)
    doc.loads()

    for cls in (CppExtractor, PythonExtractor):
        extractor = cls()
        extractor.traverse_entry()
        doc.merge(extractor.entry_list)

    doc.dumps()


if __name__ == '__main__':
    main()
