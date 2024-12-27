import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

class main{
  public static void main(String[] args){

    String filePath = "./testInput.txt";
    List<String> data = new ArrayList<>();
    List<Integer> col1 = new ArrayList<>();
    List<Integer> col2 = new ArrayList<>();

    int totalSimilarityScore = 0;

    //READ THE FILE
    try(BufferedReader puzzleDataHandle = new BufferedReader(new FileReader(filePath)))
    {
      String line;
      while((line=puzzleDataHandle.readLine()) != null ){
	data.add(line);
    }
    }catch(IOException e){
      e.printStackTrace();
    }

    for(String dataPoint:data){
      String[] arr = dataPoint.split("   ");
      col1.add(Integer.parseInt(arr[0]));
      col2.add(Integer.parseInt(arr[1]));
    }

    int[] col1_arr = col1.stream().mapToInt(Integer::intValue).toArray() ;
    int[] col2_arr=col2.stream().mapToInt(Integer::intValue).toArray();

    for(int i:col1_arr){
      int count = 0;
      for(int j:col2_arr){
	if(i==j)
	  count += 1;
      }
      totalSimilarityScore += count*i;
    }
    System.out.println(totalSimilarityScore);
    }
}
