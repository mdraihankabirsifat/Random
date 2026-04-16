
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;

public class Ex5_FileCopyDemo {

    public static void main(String args[]) throws Exception {

        String source = "src.mp4";
        String destination = "copy.mp4";

        InputStream in = new FileInputStream(source);
        OutputStream out = new FileOutputStream(destination);

        byte[] b = new byte[1024];

        int chunks = in.available() / b.length;

        for (int i = 0; i < chunks; i++) {
            in.read(b);
            out.write(b);
        }

        b = new byte[in.available()];

        in.read(b);
        out.write(b);

        in.close();
        out.close();
    }
}

/*
Key Notes:

1. Used to copy files (binary safe).
2. Uses buffer (byte array) → efficient.
3. Reads chunk by chunk → faster.
4. InputStream → read source.
5. OutputStream → write destination.
6. VERY IMPORTANT real-world example.
*/