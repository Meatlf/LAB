import argparse
parser = argparse.ArgumentParser()
parser.parse_args("echo")
args = parser.parse_args()
print(args.echo)
