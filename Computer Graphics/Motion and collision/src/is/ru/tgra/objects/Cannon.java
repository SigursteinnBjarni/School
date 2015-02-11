package is.ru.tgra.objects;

import java.nio.FloatBuffer;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Input;
import com.badlogic.gdx.graphics.GL11;

public class Cannon implements GameObject{

	public FloatBuffer vertexBuffer;
	public float rotation;
	
	public Cannon(FloatBuffer f) {
		vertexBuffer = f;
		rotation = 0;
	}
	
	@Override
	public void draw() {
		Gdx.gl11.glPushMatrix();
		Gdx.gl11.glColor4f(0f, 0f, 0f, 0f);
		Gdx.gl11.glVertexPointer(2, GL11.GL_FLOAT, 0, vertexBuffer);
		Gdx.gl11.glTranslatef(400, 0, 0);
		Gdx.gl11.glRotatef(rotation, 0, 0, 1);
		Gdx.gl11.glScalef(0.8f, 4f, 1);
		Gdx.gl11.glDrawArrays(GL11.GL_TRIANGLE_STRIP, 0, 4);
		Gdx.gl11.glPopMatrix();
		
	}
	
	@Override
	public void update(float deltaTime) {
		if(Gdx.input.isKeyPressed(Input.Keys.LEFT)) {
			rotation += 10f * deltaTime;
		}
		else if(Gdx.input.isKeyPressed(Input.Keys.RIGHT)) {
			rotation -= 10f * deltaTime;
		}
	}

	@Override
	public boolean checkCollision() {
		// TODO Auto-generated method stub
		return false;
	}

}
