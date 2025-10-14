import subprocess
import os

class Builder:
    def compile_file(self, compiler, file, output_file, wait=True, ops=[]):
        if os.path.isdir(file):
            raise TypeError(f"'{file}' is dir")

        process = subprocess.Popen([compiler, file, "-o", output_file, *ops])

        if wait:
            process.wait()

builder = Builder()
builder.compile_file("g++", "src/main.cpp", "bin/shell")