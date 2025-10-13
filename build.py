import subprocess
import os

class Builder:
    def __init__(self):
        self.processes = []

        self.config = {
            "compilate_dir": {
                "wait": True,
            },
            "compilate_file": {
                "wait": True
            }
        }

    def compile_dir(self, dir, out_dir, ops=[]):
        if not os.path.isdir(dir):
            raise TypeError(f"'{dir}' is not dir")

        for file in os.listdir(dir):
            if os.path.isdir(f"{dir}/{file}"):
                if file == "lib":
                    continue
                self.compile_dir(f"{dir}/{file}")
            else:
                process = subprocess.Popen(["g++" if file.endswith(".cpp") else "gcc", f"{dir}/{file}", "-o", f"{out_dir}/{os.path.splitext(file)[0]}", *ops])
                self.processes.append(process)

        if self.config.get("compilate_dir").get("wait"):
            for i, process in enumerate(self.processes):
                print(f"Compile {process.args[1]}")
                process.wait()
                self.processes.pop(i)

    def compile_file(self, file, output_file, ops=[]):
        if os.path.isdir(file):
            raise TypeError(f"'{file}' is dir")

        process = subprocess.Popen(["g++" if file.endswith(".cpp") else "gcc", file, "-o", output_file, *ops])

        if self.config.get("compilate_file").get("wait"):
            process.wait()

builder = Builder()
builder.compile_file("src/main.cpp", "bin/shell")