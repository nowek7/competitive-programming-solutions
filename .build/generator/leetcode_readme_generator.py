import os
import sys
from typing import List

ROOT_DIR = os.path.join(os.path.dirname(os.path.dirname(__file__)), '..')
sys.path.append(ROOT_DIR)
CURRENT_DIR = os.path.dirname(__file__)
PARENT_DIR = os.path.abspath(os.path.join(CURRENT_DIR, '..'))
sys.path.append(PARENT_DIR)
UTILS_DIR = os.path.join(PARENT_DIR, 'utils')
sys.path.append(UTILS_DIR)

from readme_generator import ReadmeGenerator  # noqa: E402
from numbers_util import (    # noqa: E402
    is_roman_number,
    is_end_of_ordinal_number
)
import markdown_util as mdu  # noqa: E402

class LeetCodeReadmeGenerator(ReadmeGenerator):
    def __init__(self):
        super().__init__()

        self.__m_base_url = 'https://leetcode.com'
        self.m_platform = 'LeetCode'
        self.m_directory = os.path.join(ROOT_DIR, self.m_platform)
        self.m_readme = os.path.join(ROOT_DIR, self.m_platform, 'README.md')

    def sort_problems_by_name(self, problem_names: List[str]) -> List[str]:
        def comp(s: str) -> int:
            return int(s[:s.find('_')])

        try:
            problem_names.sort(key=comp)
        except Exception as ex:
            print(f"No matching pattern - {ex.args}")

        return problem_names

    def get_bullet_list_from_files(self, file_paths: list[str]) -> str:
        bullet_list = '';
        for entry in file_paths:
            raw_problem_name = entry.rsplit('.', 1)[0]
            problem_name = self.filename_to_problem_name(raw_problem_name)
            problem_url = self.get_url_to_problem(raw_problem_name)

            bullet_list += mdu.get_entry_bullet_list(mdu.get_hyperlink(problem_url, problem_name))

        return bullet_list

    def filename_to_problem_name(self, raw_problem_name: str) -> str:
        words = raw_problem_name.split('_')
        assert(len(words) > 1)

        problem_name = f'{words[0]}. {words[1].capitalize()}'
        for i in range(2, len(words)):
            word = words[i];
            if is_roman_number(word):
                problem_name += f' {word.upper()}'
            elif is_end_of_ordinal_number(word):
                problem_name += f'-{word}'
            elif len(word) >= 2:
                problem_name += f' {word.capitalize()}'
            else:
                problem_name += f' {word}'

        # Special case
        if words[0] == '380':
            problem_name = f'{problem_name[:-3]}0(1)'

        return problem_name

    def get_url_to_problem(self, raw_problem_name: str) -> str:
        path_url = raw_problem_name[raw_problem_name.find('_') + 1::]
        path_url = path_url.replace('_', '-')
        path_url = path_url.replace('%', '')
        path_url = path_url.lower()
        return f'{self.__m_base_url}/problems/{path_url}/description/'
