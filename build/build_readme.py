#!/usr/bin/python3

import md_utils as mdu

import os
from os import path
from typing import Callable, NoReturn

PLATFORMS = {
    # 'AtCoder': '',
    # 'CodeForces': 'https://codeforces.com/',
    # 'HackerRank': 'https://www.hackerrank.com/',
    'LeetCode': 'https://leetcode.com'
}

def filename_to_problem_name(raw_problem_name: str) -> str:
    words = raw_problem_name.split('_')
    assert(len(words) > 1)
    problem_name = f'{words[0]}.'
    for i in range(1, len(words)):
        if len(words[i]) > 2:
            problem_name += f' {words[i].capitalize()}';
        else:
            problem_name += f' {words[i]}';

    return problem_name

def filename_to_problem_url_path(raw_problem_name: str) -> str:
    problem_url = raw_problem_name[raw_problem_name.find('_') + 1::]
    problem_url = problem_url.replace('_', '-')
    problem_url = problem_url.lower()
    return problem_url

def get_url_to_problem(platform_name: str, problem_name: str) -> str:
    base_url = PLATFORMS[platform_name]
    if platform_name == 'LeetCode':
        base_url += f'/problems/{problem_name}/description/'

    return base_url

def get_bullet_list_from_files(platform_name: str, file_paths: list[str]) -> str:
    bullet_list = '';
    for entry in file_paths:
        raw_problem_name = entry.rsplit('.', 1)[0]
        problem_name = filename_to_problem_name(raw_problem_name)
        problem_url_path = filename_to_problem_url_path(raw_problem_name)
        problem_url = get_url_to_problem(platform_name, problem_url_path)
        bullet_list += mdu.get_entry_bullet_list(mdu.get_hyperlink(problem_url, problem_name))
    return bullet_list

def create_content(platform_name: str, solutions: dict) -> str:
    content = mdu.get_header(platform_name, 1)
    size = len(solutions)
    for level, files in solutions.items():
        if files:
            content += mdu.get_header(level, 2)
            content += get_bullet_list_from_files(platform_name, files)
            if size > 1:
                content += mdu.get_empty_lines(1)
            size -= 1

    return content

def create_readme_file(platform_path: str, content: str) -> NoReturn:
    readme_file = get_readme_path(platform_path)
    with open(readme_file, 'w+') as file:
        file.write(content)

def get_platform_path(base_path: str, platform: str) -> str:
    return path.join(base_path, platform)

def get_readme_path(platform_path: str) -> str:
    return path.join(platform_path, 'README.md')

def get_solution_files(platform_path: str) -> dict:
    levels = [ path_name for path_name in os.listdir(platform_path)
             if path.isdir(path.join(platform_path, path_name))]
    solutions = { level: [] for level in levels }

    comp: Callable[[str], int] = lambda s: int(s[:s.find('_')])
    for level in levels:
        solutions[level] = os.listdir(path.join(platform_path, level))
        try:
            solutions[level].sort(key=comp)
        except:
            raise ValueError("No matching pattern")

    return solutions

def run() -> NoReturn:
    current_dir = os.getcwd()
    for name in PLATFORMS:
        platform_path = get_platform_path(current_dir, name)
        files = get_solution_files(platform_path)
        content = create_content(name, files)
        create_readme_file(platform_path, content)


if __name__ == "__main__":
    run()
