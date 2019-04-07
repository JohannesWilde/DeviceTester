import re
from os import path


if __name__ == "__main__":
    filepath = "./iom328p.h"

    conversionMacros = ["_SFR_MEM", "_SFR_IO"]
    regularExpressions = [re.compile("#define\s*(.*?)\s*({conversionMacro})(\d+)\\((0x[0-9A-Fa-f]+)\\)".format(**{"conversionMacro": macro}))
                                                                                        for macro in conversionMacros]
    filenameParts = path.splitext(path.basename(filepath))
    outputFilename = "{filename}_converted{fileextension}".format(**{"filename": filenameParts[0], "fileextension": filenameParts[1]})
    with open(filepath, "r") as file, open(outputFilename, "w") as outputFile:
        for line in file:
            for regularExpression in regularExpressions:
                line = re.sub(regularExpression, "#define \\1_REGISTER \\4\n#define \\1_TYPE uint\\3_t\n#define \\1_ACCESS"
                                                 " \\2\\3\n#define \\1 \\1_ACCESS(\\1_REGISTER)", line)
            outputFile.write(line)


    exit(0)


