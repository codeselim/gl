# import sys
# sys.path.insert(0, '..')

from pyutils.run_utils import execute_shell_and_get_stdout


def execute_test(args):
    PATH_TO_BINARY = "./gl"
    return execute_shell_and_get_stdout(PATH_TO_BINARY, args)
    # if err:
    #     print err

    # return out
