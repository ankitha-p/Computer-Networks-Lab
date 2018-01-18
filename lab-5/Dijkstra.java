import java.util.Scanner; //Scanner Function to take in the Input Values
 
public class Dijkstra
{
    static Scanner scan=new Scanner(System.in); // scan is a Scanner Object
    static int nodes;
    public static void main(String[] args)
    {
	System.out.println("Enter the number of nodes");
	nodes=scan.nextInt();
        int[] preD = new int[nodes];
        int min = 9999, nextNode = 0; // min holds the minimum value, nextNode holds the value for the next node.
        int[] distance = new int[nodes]; // the distance matrix
        int[][] matrix = new int[nodes][nodes]; // the actual matrix
        int[] visited = new int[nodes]; // the visited array
 
        System.out.println("Enter the cost matrix");
 
        for (int i = 0; i < distance.length; i++){
            visited[i] = 0; //initialize visited array to zeros
            preD[i] = 0;
 
            for (int j = 0; j < distance.length; j++){
                matrix[i][j] = scan.nextInt(); //fill the matrix
                if (matrix[i][j]==0)
                    matrix[i][j] = 9999; // make the zeros as 999
            }
        }

 	System.out.println("Enter the source node:");
	int source=scan.next().charAt(0)-65;
        distance = matrix[source]; //initialize the distance array
        visited[source] = 1; //set the source node as visited
        distance[source] = 0; //set the distance from source to source to zero which is the starting point
 
        for (int counter = 0; counter < nodes; counter++)
        {
            min = 9999;
            for (int i = 0; i < nodes; i++)
            {
                if (min > distance[i] && visited[i]!=1)
                {
                    min = distance[i];
                    nextNode = i;
                }
            }
 
            visited[nextNode] = 1;
            for (int i = 0; i < nodes; i++){
                if (visited[i]!=1){
                    if (min+matrix[nextNode][i] < distance[i]){
             	           distance[i] = min+matrix[nextNode][i];
                	   preD[i] = nextNode;
                    } 
                } 
            } 
        }

	System.out.println("\nThe distance matrix is as follows:\n");
	for(int i=0;i<nodes;i++)
		System.out.print("|"+ (char)(65+i));
	System.out.println();
        for(int i = 0; i < nodes; i++)
            System.out.print("|" + distance[i]);
         System.out.println("|");
 
        for (int i = 0; i < nodes; i++)
        {
           System.out.print("Path for "+(char)(i+65)+" is = "  + (char)(i+65));
           int j = i;
           do{
                j = preD[j];
	        if(j!=0) System.out.print(" <- " + (char)(j+65));
           }while(j != 0);
 	   System.out.println(" <- "+ (char)(source+65));
        }
    }
}
