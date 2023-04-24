import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class Hangman implements KeyListener {
    private int count = 7;
    

    public static void main(String[] args) {
        System.out.print("文字を入力してください: ");
    }

    @Override
    public void keyTyped(KeyEvent e) {
        if (Character.isLowerCase(e.getKeyChar())) {

        }
    }

    @Override
    public void keyPressed(KeyEvent e) {

    }

    @Override
    public void keyReleased(KeyEvent e) {

    }
}
