package is.ru.tgra.objects;

import is.ru.tgra.util.Point2D;
import is.ru.tgra.util.Util;

import java.nio.FloatBuffer;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.GL11;

/**
 * Game object that represents Boxes on the field
 * @author DrepAri
 *
 */
public class Box implements GameObject {

	public int SIZE = 50;
	public Point2D pos;
	public FloatBuffer vertexBuffer;
	public CannonBall cannonBall;
	public float scale_x;
	public float scale_y;
	
	public Box(Point2D p, FloatBuffer f, CannonBall c) {
		pos = p;
		vertexBuffer = f;
		cannonBall = c;
		
		scale_x = 1;
		scale_y = 1;
	}
	
	@Override
	public void draw() {
		Gdx.gl11.glPushMatrix();
		Gdx.gl11.glColor4f(0.8f, 0.0f, 0.0f, 1.0f);
		Gdx.gl11.glVertexPointer(2, GL11.GL_FLOAT, 0, vertexBuffer);
		Gdx.gl11.glTranslatef(pos.getX(), pos.getY(), 0);
		Gdx.gl11.glScalef(scale_x, scale_y, 0);
		Gdx.gl11.glDrawArrays(GL11.GL_TRIANGLE_STRIP, 0, 4);
		Gdx.gl11.glPopMatrix();
		
	}
	
	@Override
	public void update(float deltaTime) {
		
		scale_x += Gdx.input.getDeltaX() * deltaTime;
		scale_y += Gdx.input.getDeltaY() * deltaTime;
		
	}

	/**
	 * checks on collisions based on thit and phit formulas
	 */
	@Override
	public boolean checkCollision() {
		if(cannonBall.isMoving) {
			/**
			 * Left Side
			 */
			Point2D start = new Point2D((pos.getX() - (SIZE/2 * scale_x)), (pos.getY() - (SIZE/2) * scale_y));
			Point2D end = new Point2D((pos.getX() - (SIZE/2) * scale_x), (pos.getY() + (SIZE/2) * scale_x));
			
			if (checkCollision(start, end)) {
				return true;
			}
			
			/**
			 * Bottom Side
			 */
			start.setX(pos.getX() - (SIZE/2 * scale_x));
			start.setY(pos.getY() - (SIZE/2 * scale_y));
			end.setX(pos.getX() + (SIZE/2 * scale_x));
			end.setY(pos.getY() - (SIZE/2 * scale_y));
			
			if (checkCollision(start, end)) {
				return true;
			}
			
			/**
			 * Top Side
			 */
			start.setX(pos.getX() - (SIZE/2 * scale_x));
			start.setY(pos.getY() + (SIZE/2 * scale_y));
			end.setX(pos.getX() + (SIZE/2 * scale_x));
			end.setY(pos.getY() + (SIZE/2 * scale_y));
			
			if (checkCollision(start, end)) {
				return true;
			}
			
			/**
			 * Right Side
			 */
			start.setX(pos.getX() + (SIZE/2 * scale_x));
			start.setY(pos.getY() + (SIZE/2 * scale_y));
			end.setX(pos.getX() + (SIZE/2 * scale_x));
			end.setY(pos.getY() - (SIZE/2 * scale_y));
			
			if (checkCollision(start, end)) {
				return true;
			}
		}
		
		return false;
	}
	
	private boolean checkCollision(Point2D start, Point2D end) {
		
		float thit = Util.tHit(cannonBall.pos, start, cannonBall.movementVector, Util.normalVector(start, end));
		if (thit > 0 && thit <= 1) {
			Point2D p = Util.pHit(cannonBall.pos, cannonBall.movementVector, thit);
			if(Util.isBetween(start, end, p)) {
				cannonBall.movementVector = Util.collisionResponse(cannonBall.movementVector, Util.normalVector(start, end));
				return true;
			}
		}
		
		return false;
		
	}
	

}
