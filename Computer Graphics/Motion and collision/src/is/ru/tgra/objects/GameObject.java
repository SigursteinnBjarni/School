package is.ru.tgra.objects;

/**
 * Game object class, must implement this functionality if you want to get drawn
 * @author DrepAri
 *
 */
public interface GameObject {
	
	/**
	 * Each object is responsible for drawing itself
	 */
	public void draw();
	
	/**
	 * Each object is responsible for updating its position and size
	 * @param deltaTime
	 */
	public void update(float deltaTime);
	
	/**
	 * Each object is responsible for checking for collisions
	 * @return True if collision effects the score, false otherwise
	 */
	public boolean checkCollision();

}
