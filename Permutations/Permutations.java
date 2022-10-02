public class Solution {

    public List<List<Integer>> permute(int[] num) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();

        result.add(new ArrayList<Integer>());
        List<List<Integer>> current = new ArrayList<List<Integer>>();
        for (int i = 0; i < num.length; ++i) {
          
            current.clear();
            for (List<Integer> l : result) {
           
                for (int j = 0; j < l.size()+1; ++j) {
                  
                    l.add(j, num[i]);
                    ArrayList<Integer> temp = new ArrayList<Integer>(l);
                    current.add(temp);
                    l.remove(j); 
                }
            }
        result = new ArrayList<List<Integer>>(current);
        }
        return result;
    }

}