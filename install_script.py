from subprocess import call


def init():
    with open('sample.txt') as fp:
        for line in fp:
            print line[:-2]
            print call(["pip", "install", "-Iv", line[:-2]])


if __name__ == '__main__':
    init()
