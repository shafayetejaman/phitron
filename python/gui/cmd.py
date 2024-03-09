import subprocess

command = str()

with open("command.txt", "r") as file:
    command = file.read()

output = subprocess.run(["powershell", "-Command", command], capture_output=True)

result = output.stdout.decode("utf-8")
print(result)