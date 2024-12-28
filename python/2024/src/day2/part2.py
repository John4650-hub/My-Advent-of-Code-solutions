def is_report_safe(report):
    # Check if the report is strictly increasing or decreasing by at least 1 and at most 3
    increasing = all(1 <= report[i + 1] - report[i] <= 3 for i in range(len(report) - 1))
    decreasing = all(1 <= report[i] - report[i + 1] <= 3 for i in range(len(report) - 1))
    return increasing or decreasing

def run_level_check_with_dampener(report):
    # Check if the report is already safe
    if is_report_safe(report):
        return True

    # Try removing each level one by one and check if the resulting report is safe
    for i in range(len(report)):
        new_report = report[:i] + report[i+1:]
        if is_report_safe(new_report):
            return True

    return False

with open("../../../../input/myInput.txt", "r") as fhand:
    unusual_data = [list(map(int, i.strip().split())) for i in fhand.readlines()]

safe_reports = 0

for report in unusual_data:
    if run_level_check_with_dampener(report):
        safe_reports += 1

print(safe_reports)
