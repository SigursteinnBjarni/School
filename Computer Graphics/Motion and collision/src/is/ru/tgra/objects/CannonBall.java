package is.ru.tgra.objects;

import is.ru.tgra.util.Point2D;
import is.ru.tgra.util.Vector2D;

import java.nio.FloatBuffer;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Input;
import com.badlogic.gdx.graphics.GL11;

/**
 * Game object that represents the cannon ball
 * @author DrepAri
 *
 */
public class CannonBall implements GameObject{

	public FloatBuffer vertexBuffer;
	public boolean isMoving;
	public Cannon cannon;
	public Vector2D movementVector;
	public Point2D pos;
	public int VELOCITY = 150;
	
	public CannonBall(FloatBuffer f, Cannon c) {
		vertexBuffer = f;
		cannon = c;
		pos = new Point2D(400, 0);
		isMoving = false;
	}
	
	@Override
	public void draw() {
		Gdx.gl11.glPushMatrix();
		Gdx.gl11.glColor4f(0.5f, 0.0f, 0.5f, 1.0f);
		Gdx.gl11.glVertexPointer(2, GL11.GL_FLOAT, 0, vertexBuffer);
		Gdx.gl11.glTranslatef(pos.getX(), pos.getY(), 0);
		Gdx.gl11.glScalef(15f, 15f, 0);
		Gdx.gl11.glDrawArrays(GL11.GL_TRIANGLE_FAN, 0, 24);
		Gdx.gl11.glPopMatrix();
		
	}

	@Override
	public void update(float deltaTime) {
		if(!isMoving && Gdx.input.isKeyPressed(Input.Keys.SPACE)) {
			isMoving = true;
			movementVector = new Vector2D();
	
			movementVector.setX((float) (deltaTime * VELOCITY *  Math.cos(Math.toRadians(cannon.rotation) + (Math.PI/2))));
			movementVector.setY((float) (deltaTime * VELOCITY *  Math.sin(Math.toRadians(cannon.rotation) + (Math.PI/2))));
		}
		else if(isMoving){
			move();
		}
	}

	@Override
	public boolean checkCollision() {
		// TODO Auto-generated method stub
		return false;
	}
	
	public void move() {
		pos.setX(pos.getX() + movementVector.getX());
		pos.setY(pos.getY() + movementVector.getY());
	}
	
	public void reset() {
		isMoving = false;
		pos.setX(400);
		pos.setY(0);
		
	}

}
