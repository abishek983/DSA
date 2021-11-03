import java.io.*;
import java.util.*;

public class Main {

	static String max;
	public static void findMaximum(String str, int k, int idx) {
		//base case
		if(k==0 || idx >= str.length()){
            //checking whether the string is greater than the max so far
		    for(int i=0; i<max.length(); i++){
		        if(max.charAt(i) > str.charAt(i)){
		            break;
		        }
                else if(str.charAt(i) > max.charAt(i)){
                    max = str;
                    break;
                }
            }
		    return;
		}
		
		//finding the index which has higest value after index 'idx'
        char currChar = str.charAt(idx);
        int maxValCharIdx = idx; 
        for(int i= idx+1; i<str.length(); i++){
            if(str.charAt(i) - '0' > currChar - '0'){
                maxValCharIdx = i;
                String newStr = str.substring(0, idx) + str.charAt(maxValCharIdx) + str.substring(idx+1, maxValCharIdx) + currChar + str.substring(maxValCharIdx+1);
                findMaximum(newStr, k-1, idx+1);
            }
        }
		if(idx == maxValCharIdx){
            findMaximum(str, k, idx+1);
        }
	}
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		int k = scn.nextInt();
		max = str;
		findMaximum(str, k, 0);
		System.out.println(max);
	}

}