import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

class main{
  static int getProductSum(List<String> arrList){
    String regex = "\\d{1,3},\\d{1,3}";
    Pattern pattern = Pattern.compile(regex);
    int total = 0;
    for(String i:arrList){
      Matcher matcher = pattern.matcher(i);
      while(matcher.find()){
	String[] num = matcher.group().split(",");
	total += Integer.parseInt(num[0]) * Integer.parseInt(num[1]);
      }
    }
    return total;
  }
  public static void main(String[] args){
    String data="";
    String filePath = "./foo.txt";
    //READ FILE LINE BY LINE
    try(BufferedReader puzzleData = new BufferedReader(new FileReader(filePath))){
      String line;
      while((line=puzzleData.readLine())!=null){
	data+=line;
      }
    }catch(IOException e){
      e.printStackTrace();
    }

    String regex = "mul\\(\\d{1,3},\\d{1,3}\\)";
    Pattern pattern = Pattern.compile(regex);
    Matcher matcher = pattern.matcher(data);
    List<String> allMatches = new ArrayList<>();
    while(matcher.find()){
     allMatches.add(matcher.group());
    }
    int sum = getProductSum(allMatches);
    System.out.println(sum);
  }
}
