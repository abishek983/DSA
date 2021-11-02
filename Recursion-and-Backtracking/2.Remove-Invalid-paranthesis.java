import java.io.*;
import java.util.*;

public class Main {

	public static void solution(String str, int minRemoval, HashSet<String> ans) {
		//base case
		if(minRemoval == 0){
		    if(ans.contains(str) == false){
		        if(getMin(str) == 0){
		            System.out.println(str);
		        }
		        ans.add(str);
		    }
		    return;
		}
		
		for(int i=0; i<str.length(); i++){
		      solution(str.substring(0, i) + str.substring(i+1), minRemoval-1, ans);
		}
	}

	public static int getMin(String str){
		//write your code here
		Stack<Character> st = new Stack<>();
		int count = 0;
		for(char c: str.toCharArray()){
		    if(c == ')'){
		        if(st.size() > 0){
		            st.pop();
		        }
		        else{
		            count++;
		        }
		    }
		    else{
		        st.push(c);
		    }
		}
		return count + st.size();
	}
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		solution(str, getMin(str),new HashSet<>());
	}
		
}