package is.ru.tgra.objects;

public abstract class CelestialObject {

	protected String texture_path;  
	protected float rotation_angle;
	protected float rotation_speed;
	protected float orbit_angle;
	protected float orbit_speed;
	protected Sphere sphere;
	protected float size;
	
	public CelestialObject(String texture_path, float orbit_angle, float orbit_speed, float rotation_angle, float rotation_speed, float size) {
		this.texture_path = texture_path;
		this.orbit_angle = orbit_angle;
		this.orbit_speed = orbit_speed;
		this.rotation_angle = rotation_angle;
		this.rotation_speed = rotation_speed;
		this.size = size;
		
		sphere = new Sphere(100, 100, texture_path);
	}
	
	public abstract void draw();
	public abstract void update(float deltaTime);

	@Override
	public String toString() {
		return "CelestialObject [texture_path=" + texture_path +", rotation_angle=" + rotation_angle
				+ ", orbit_angle=" + orbit_angle
				+ ", sphere=" + sphere + "]";
	}
	
	
}
