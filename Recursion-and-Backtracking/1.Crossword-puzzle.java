//https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/crossword-puzzle-official/ojquestion

import java.io.*;
import java.util.*;

public class Main {

  public static void solution(char[][] arr, String[] words, int vidx) {
    //base case to call the print function
    if(vidx == words.length){
        print(arr);
        return;
    }

    //try all possible cases
    for(int i=0; i<arr.length; i++){
        for(int j=0; j<arr[0].length; j++){
            //check whether we can start at this position
            if(arr[i][j] == '-' || arr[i][j] == words[vidx].charAt(0)){
                //check && place whether we can place horizontally & then backtrack
                if(canBePlaceHorizontally(arr, words[vidx], i, j)){
                    boolean[] whoPlace = placeHorizontally(arr, words[vidx], i, j);
                    solution(arr, words, vidx+1);
                    unPlaceHorizontally(arr, whoPlace, i, j);
                }
                //check && place whether we can place vertically & then backtrack
                if(canBePlaceVertically(arr, words[vidx], i, j)){
                    boolean[] whoPlace = placeVertically(arr, words[vidx], i, j);
                    solution(arr, words, vidx + 1);
                    unPlaceVertically(arr, whoPlace, i, j);
                }
            }
        }
    }
  }

  public static boolean canBePlaceHorizontally(char[][] arr, String word, int i, int j){
      if(j-1 >=0 && arr[i][j-1]!='+'){
          return false;
      }
      if(j + word.length() < arr[0].length && arr[i][j + word.length()] != '+'){
          return false;
      }

      for(int jj=0; jj<word.length(); jj++){
          if(j + jj >= arr[0].length)
            return false;

         if(arr[i][j+jj] != '-' && arr[i][j+jj] != word.charAt(jj)){
             return false;
         }
      }

      return true;
  }

  public static boolean canBePlaceVertically(char[][] arr, String word, int i, int j){
      if(i-1 >=0 && arr[i-1][j]!='+'){
          return false;
      }
      if(i + word.length() < arr.length && arr[i + word.length()][j] != '+'){
          return false;
      }

      for(int ii=0; ii<word.length(); ii++){
          if(i + ii >= arr.length)
            return false;

         if(arr[i + ii][j] != '-' && arr[i + ii][j] != word.charAt(ii)){
             return false;
         }
      }

      return true;
  }


  public static boolean[] placeHorizontally(char[][] arr, String word, int i, int j){
      boolean[] placed = new boolean[word.length()];

      for(int jj=0; jj<word.length(); jj++){
          if(arr[i][j+jj] == '-'){
              arr[i][j+jj] = word.charAt(jj);
              placed[jj] = true;
          }
      }
      return placed;
  }

  public static boolean[] placeVertically(char[][] arr, String word, int i, int j){
      boolean[] placed = new boolean[word.length()];

      for(int ii=0; ii<word.length(); ii++){
          if(arr[i + ii][j] == '-'){
              arr[i + ii][j] = word.charAt(ii);
              placed[ii] = true;
          }
      }
      return placed;
  }

  public static void unPlaceHorizontally(char[][] arr, boolean[] word, int i, int j){
      for(int jj=0; jj<word.length; jj++){
          if(word[jj] == true){
              arr[i][j+jj] = '-';
          }
      }
  }

  public static void unPlaceVertically(char[][] arr, boolean[] word, int i, int j){
      for(int ii=0; ii<word.length; ii++){
          if(word[ii] == true){
              arr[i + ii][j] = '-';
          }
      }
  }

  public static void print(char[][] arr) {
    for (int i = 0 ; i < arr.length; i++) {
      for (int j = 0 ; j < arr.length; j++) {
        System.out.print(arr[i][j]);
      }
      System.out.println();
    }

  }
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    char[][] arr = new char[10][10];
    for (int i = 0 ; i < arr.length; i++) {
      String str = scn.next();
      arr[i] = str.toCharArray();
    }
    int n = scn.nextInt();
    String[] words = new String[n];
    for (int i = 0 ; i  < words.length; i++) {
      words[i] = scn.next();
    }
    solution(arr, words, 0);
  }
}