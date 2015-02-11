package is.ru.tgra;

import com.badlogic.gdx.backends.lwjgl.LwjglApplication;

public class DesktopRunner {
 public static void main(String[] args) {
	 new LwjglApplication(new Boxes3(), "Madness Box", 640, 480, false);
 }
}
