import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.stream.IntStream;

class main{
  public static boolean all(boolean[] arr){
    for(boolean v: arr){
      if (v==false){
	return false;
      }
    }
    return true;
    }
  public static boolean isReportSafe(String report){
    int[] lvs = Arrays.stream(report.split(" ")).mapToInt(Integer::parseInt).toArray();
    int sizeArr = lvs.length - 1;
    boolean[] increasing = new boolean[sizeArr];
    boolean[] decreasing = new boolean[sizeArr];
    for(int i:IntStream.range(0,sizeArr).toArray()){
      if(1<=lvs[i+1]-lvs[i] && lvs[i+1]-lvs[i]<=3)
	increasing[i] = true;
      else
	increasing[i]=false;
    }
    //check decreasing
    for(int i:IntStream.range(0,sizeArr).toArray()){
      if(1<=lvs[i]-lvs[i+1] && lvs[i]-lvs[i+1]<=3)
	decreasing[i] = true;
      else
	decreasing[i]=false;
    }
    return all(increasing) || all(decreasing);
  }

  public static void main(String[] args)
  {
    List<String> unusualData = new ArrayList<>();
    int safe=0;
    try(BufferedReader puzzleDataHandle = new BufferedReader(new FileReader("./foo.txt"))){
      String line;
      while((line=puzzleDataHandle.readLine())!=null)
	unusualData.add(line);
    }catch(IOException e){
      e.printStackTrace();
    }
    for(String ln:unusualData){
      if (isReportSafe(ln))
	safe+=1;
    }

    System.out.println(safe);
  }
}
