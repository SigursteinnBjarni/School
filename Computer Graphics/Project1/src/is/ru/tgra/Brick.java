package is.ru.tgra;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.GL11;

public class Brick extends Boxes3 {
	private float x;
	private float y;

	public Brick(float x, float y){
		this.x = x;
		this.y = y;
	}
	
	public void draw(){
		Gdx.gl11.glPushMatrix();
		Gdx.gl11.glColor4f(0.6f, 0.0f, 0.0f, 1.0f);
		Gdx.gl11.glTranslatef(x, y, 0.0f);
		Gdx.gl11.glDrawArrays(GL11.GL_TRIANGLE_STRIP, 0, 4);
		Gdx.gl11.glPopMatrix();
	}
}
