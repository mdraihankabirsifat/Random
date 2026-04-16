
import java.io.*;

public class Ex10_BufferedWriterDemo {

    public static void main(String args[]) throws Exception {

        Reader fr = new FileReader("TestFile.java");
        BufferedReader br = new BufferedReader(fr);

        FileWriter fw = new FileWriter("TestFileCopy.java");
        BufferedWriter bw = new BufferedWriter(fw);

        while (true) {
            String s = br.readLine();
            if (s == null) {
                break;
            }
            bw.write(s);
            bw.newLine();
        }

        bw.close();
        fw.close();
        br.close();
        fr.close();
    }
}

/*
Key Notes:

1. BufferedWriter → efficient writing.
2. newLine() → platform independent newline.
3. Often used with BufferedReader.
4. Ideal for file copying (text).
*/
