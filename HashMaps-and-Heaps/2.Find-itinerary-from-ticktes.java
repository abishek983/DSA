//https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/hashmap-and-heaps/find-itinerary-from-tickets-official/ojquestion

import java.util.*;

public class Main {
    public static void findItenary(HashMap<String, String> tickets){
        //find starting point
        HashMap<String, Boolean> isSrc = new HashMap<>();

        for(String src: tickets.keySet()){
            String des = tickets.get(src);

            isSrc.put(des, false);
            if(isSrc.containsKey() == false){
                isSrc.put(src, true);
            }
        }

        String startingPoint = "";
        for(String src: isSrc.keySet()){
            if(isSrc.get(src) == true){
                startingPoint = src;
                break;
            }
        }

        // using the src find the path
        String path = "";
        while(tickets.containsKey(startingPoint) == false){
            path += startingPoint + "->";
            startingPoint = tickets.get(startingPoint);
        }

        path += startingPoint + ".";
        System.out.println(path);
    }


	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int noofpairs_src_des = scn.nextInt();
		HashMap<String, String> map = new HashMap<>();
		for (int i = 0; i < noofpairs_src_des; i++) {
			String s1 = scn.next();
			String s2 = scn.next();
			map.put(s1, s2);	
		}

		//write your code here
        findItenary(map);
	}
}
