package is.ru.tgra;

import com.badlogic.gdx.backends.lwjgl.LwjglApplication;

public class GameRunner {
	public static void main(String[] args) {
		 new LwjglApplication(new WreckingBall(), "Wrecking Ball", 800, 600, false);
	}
}
