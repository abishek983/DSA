//https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/hashmap-and-heaps/number-of-employees-under-every-manager-official/ojquestion
import java.io.*;
import java.util.*;

public class Main {
  public static int findAns(HashMap<String, HashSet<String>> map, HashMap<String, Integer> ans, String man){
    if(map.containsKey(man)==false){
        ans.put(man, 0);
        return 1;
    }
    int count = 0;
    for(String emp: map.get(man)){
        count += findAns(map, ans, emp);
    }
    
    ans.put(man, count);
    return count+1;
  }    
    
    

  public static void main(String[] args){
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    
    //write your code here
    HashMap<String, HashSet<String>> map = new HashMap<>();
    String ceo = "";
    for(int i=0; i<n; i++){
        String e = scn.next();
        String m = scn.next();
        
        if(e.equals(m)){
            ceo = e;
        }else if(map.containsKey(m)){
            map.get(m).add(e);
        }else{
            HashSet<String> hs = new HashSet<>();
            hs.add(e);
            map.put(m, hs);
        }
    }
    
    HashMap<String, Integer> ans = new HashMap<>();
    // System.out.println(ceo);  
    
    findAns(map, ans, ceo);
    
    for(String c: ans.keySet()){
        System.out.println(c + " " + ans.get(c));
    }
  }

}