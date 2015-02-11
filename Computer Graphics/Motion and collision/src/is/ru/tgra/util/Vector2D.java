package is.ru.tgra.util;

/**
 * POJO class representing vectors 
 * @author DrepAri
 *
 */
public class Vector2D {
	private float x;
	private float y;
	
	public Vector2D(float x, float y) {
		this.x = x;
		this.y = y;
	}
	
	public Vector2D() {
		
	}
	
	public float getX() {
		return this.x;
	}
	
	public float getY() {
		return this.y;
	}
	
	public void setX(float x) {
		this.x = x;
	}
	
	public void setY(float y) {
		this.y = y;
	}
	
	public void normalize() {
		float length = (float) Math.sqrt(((double) x*x + (double) y*y));
		
		x = x/length;
		y = y/length;
	}
}
