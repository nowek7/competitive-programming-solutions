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
import utils.markdown_util as mdu  # noqa: E402

class CoderbyteReadmeGenerator(ReadmeGenerator):
    def __init__(self):
        super().__init__()

        self.__m_base_url = 'https://coderbyte.com'
        self.m_platform = 'Coderbyte'
        self.m_directory = os.path.join(ROOT_DIR, self.m_platform)
        self.m_readme = os.path.join(ROOT_DIR, self.m_platform, 'README.md')
        
    def sort_problems_by_name(self, problem_names: List[str]) -> List[str]:
        problem_names.sort()
        return problem_names

    def get_bullet_list_from_files(self, filenames: list[str]) -> str:
        bullet_list = '';
        for entry in filenames:
            problem_name = self.filename_to_problem_name(entry)
            problem_url = self.get_url_to_problem(entry)

            bullet_list += mdu.get_entry_bullet_list(mdu.get_hyperlink(problem_url, problem_name))

        return bullet_list


    def filename_to_problem_name(self, raw_problem_name: str) -> str:
        words = raw_problem_name.split('_')
        assert words

        words = [w.capitalize() for w in words]
        return ' '.join(words)

    def get_url_to_problem(self, raw_problem_name: str) -> str:
        words = raw_problem_name.split('_')
        words = [w.capitalize() for w in words]
        path_url = '%20'.join(words)
        return f'{self.__m_base_url}/information/{path_url}'
