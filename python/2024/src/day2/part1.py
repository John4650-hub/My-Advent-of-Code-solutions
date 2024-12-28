with open("../../../../input/myInput.txt", "r") as fhand:
    unusual_data = [i.strip().split(" ") for i in fhand.readlines()]

safe_reports = 0
is_all_increasing = False
is_all_decreasing = False
by_ = [1, 2, 3]


def run_level_check(report):
    diff = 1
    index = 0
    safe = 0
    report_size = len(report)
    while diff in by_:
        if index < report_size - 1:
            diff = abs(report[index] - report[index + 1])
            index += 1
        else:
            safe += 1
            break
    return safe


# check whether increasing or decreasing
for report in unusual_data:
    report = [int(i) for i in report]
    if report[0] > report[-1]:
        # sort in descending order
        is_all_decreasing = sorted(report, reverse=True) == report
        if is_all_decreasing:
            safe_reports += run_level_check(report)
    else:
        # sort in ascending order
        is_all_increasing = sorted(report) == report
        if is_all_increasing:
            safe_reports += run_level_check(report)
print(safe_reports)
