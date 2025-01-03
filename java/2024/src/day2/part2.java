import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.stream.IntStream;

class main {
    // Helper method to check if all elements in a boolean array are true
    public static boolean all(boolean[] arr) {
        for (boolean v : arr) {
            if (!v) {
                return false;
            }
        }
        return true;
    }

    // Method to check if a report is safe
    public static boolean isReportSafe(int[] report) {
        int sizeArr = report.length - 1;
        boolean[] increasing = new boolean[sizeArr];
        boolean[] decreasing = new boolean[sizeArr];

        for (int i = 0; i < sizeArr; i++) {
            increasing[i] = 1 <= report[i + 1] - report[i] && report[i + 1] - report[i] <= 3;
            decreasing[i] = 1 <= report[i] - report[i + 1] && report[i] - report[i + 1] <= 3;
        }

        return all(increasing) || all(decreasing);
    }

    // Method to check if removing one level makes the report safe
    public static boolean checkLevelRemoval(int[] report) {
        if (isReportSafe(report)) {
            return true;
        }

        int sizeArr = report.length;

        for (int i = 0; i < sizeArr; i++) {
            int[] newReport = new int[sizeArr - 1];
            System.arraycopy(report, 0, newReport, 0, i);
            System.arraycopy(report, i + 1, newReport, i, sizeArr - i - 1);

            if (isReportSafe(newReport)) {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        List<String> unusualData = new ArrayList<>();
        int safe = 0;

        try (BufferedReader puzzleDataHandle = new BufferedReader(new FileReader("./foo.txt"))) {
            String line;
            while ((line = puzzleDataHandle.readLine()) != null) {
                unusualData.add(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        for (String ln : unusualData) {
            int[] lvs = Arrays.stream(ln.split(" ")).mapToInt(Integer::parseInt).toArray();
            if (checkLevelRemoval(lvs)) {
                safe++;
            }
        }

        System.out.println(safe);
    }
}
