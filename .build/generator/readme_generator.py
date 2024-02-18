import os
import sys
from typing import NoReturn

ROOT_DIR = os.path.dirname(os.path.dirname(__file__))
sys.path.append(ROOT_DIR)
CURRENT_DIR = os.path.dirname(__file__)
PARENT_DIR = os.path.abspath(os.path.join(CURRENT_DIR, '..'))
sys.path.append(PARENT_DIR)
UTILS_DIR = os.path.join(PARENT_DIR, 'utils')
sys.path.append(UTILS_DIR)

import utils.markdown_util as mdu  # noqa: E402

class ReadmeGenerator:
    def __init__(self):
        self.m_platform = None
        self.m_readme = None
        self.m_directory = None

    def create(self) -> NoReturn:
        assert(self.m_readme)

        problem_names = self.get_problem_names()
        content = self.generate_content(problem_names)

        with open(self.m_readme, 'w+') as file:
            file.write(content)

    def generate_content(self, problem_names: dict) -> str:
        content = mdu.get_header(self.m_platform, 1)
        size = len(problem_names)
        for level, files in problem_names.items():
            if files:
                content += mdu.get_header(level, 2)
                content += self.get_bullet_list_from_files(files)

                if size > 1:
                    content += mdu.get_empty_lines(1)
                size -= 1

        return content

    def get_problem_names(self) -> dict:
        levels = [ path_name for path_name in os.listdir(self.m_directory)
                   if os.path.isdir(os.path.join(self.m_directory, path_name))]
        problem_names = { level: [] for level in levels }

        for level in levels:
            problem_names[level] = os.listdir(os.path.join(self.m_directory, level))
            problem_names[level] = self.sort_problems_by_name(problem_names[level])

        return problem_names

