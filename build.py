import subprocess
import platform 
import shutil
import sys
import os

if platform.system() != "Linux":
    print("WARNING! Builder tested only on LINUX, if builder crash, recommend manual tune")


class Builder:
    def compile_file(self, compiler, file, output_file, wait=True, ops=[]):
        if os.path.isdir(file):
            raise TypeError(f"'{file}' is dir")

        process = subprocess.Popen([compiler, file, "-o", output_file, *ops])

        if wait:
            process.wait()

        return process

        
    def copy2(self, from_file, to_file):
        try:
            if os.path.exists(to_file):
                os.remove(to_file)
            shutil.copy2(from_file, to_file)
        except PermissionError as e:
            print(e)
            return 1

        return 0


builder = Builder()
print("Compiling", end="\r")
process = builder.compile_file("g++", "src/main.cpp", "bin/shell")

if process.returncode == 0:
    print("[OK] Compiling")

    print("Change mode", end="\r")
    os.chmod("bin/shell", 0o777)
    print("[OK] Change mode")

    print("Copying to /bin", end="\r")
    ret = builder.copy2("bin/shell", "/bin/lank")
    
    if ret == 0:
        print("[OK] Copying to /bin")
    else:
        print("[BAD] Copying to /bin")
else:
    print("[BAD] Compiling")