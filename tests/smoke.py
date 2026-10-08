"""Compile separately with make; exercise representative console behavior."""
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[1]
CASES = [('1\n0000000000001010\n4\n', '0x000A'), ('2\nFFFFFFFF\n4\n', '4294967295'), ('3\n10\n4\n', '0x0000000A')]
for input_text, expected in CASES:
    result = subprocess.run([str(ROOT / "build/example")], input=input_text,
                            text=True, capture_output=True, timeout=5, check=True)
    assert expected in result.stdout, f"Expected {expected!r} in output: {result.stdout}"
print(f"Passed {len(CASES)} smoke checks.")
