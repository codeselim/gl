sys.path.insert(0, '..')
from cli import execute_shell_and_get_stdout

def execute_test(args):
	PATH_TO_BINARY = "../gl"
	execute_shell_and_get_stdout(PATH_TO_BINARY, args)