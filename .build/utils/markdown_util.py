import os
import sys

ROOT_DIR = os.path.dirname(os.path.dirname(__file__))
sys.path.append(ROOT_DIR)
CURRENT_DIR = os.path.dirname(__file__)
PARENT_DIR = os.path.abspath(os.path.join(CURRENT_DIR, '..'))
sys.path.append(PARENT_DIR)

def get_header(text: str, level: int = 1) -> str:
    assert(level <= 6)
    header = f'{level * "#"} {text} \n'
    if level == 1:
        header += '\n';
    return header

def get_entry_bullet_list(text: str) -> str:
    return f'  - {text}\n'

def get_hyperlink(url:str , text: str) -> str:
    return f'[{text}]({url})'

def get_empty_lines(num: int = 1) -> str:
    return num * '\n';


