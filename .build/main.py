#!/usr/bin/python3

import os
import sys
from typing import NoReturn

CURRENT_DIR = os.path.dirname(__file__)
sys.path.append(CURRENT_DIR)
GENERATOR_DIR = os.path.join(CURRENT_DIR, 'generator')
sys.path.append(GENERATOR_DIR)
UTILS_DIR = os.path.join(CURRENT_DIR, 'utils')
sys.path.append(UTILS_DIR)

from leetcode_readme_generator import LeetCodeReadmeGenerator
from coderbyte_readme_generator import CoderbyteReadmeGenerator

PLATFORMS = {
    'LeetCode': LeetCodeReadmeGenerator(),
    'Coderbyte': CoderbyteReadmeGenerator()
}

def run() -> NoReturn:
    for name, readme_generator in PLATFORMS.items():
        print(f'Start generating {name} README')
        try:
            readme_generator.create()
            print('Success')
        except Exception as ex:
            print(ex.args)
            print('Generate README ends with failure')

if __name__ == "__main__":
    run()
