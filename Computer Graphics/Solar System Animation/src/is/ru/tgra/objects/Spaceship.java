package is.ru.tgra.objects;

import java.util.List;

import org.lwjgl.opengl.GL11;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g3d.ModelLoaderHints;
import com.badlogic.gdx.graphics.g3d.loaders.wavefront.ObjLoader;
import com.badlogic.gdx.graphics.g3d.model.Model;

import is.ru.tgra.util.Point3D;

public class Spaceship {
	
	private Point3D position;
	private ObjLoader objLoader;
	private Model model;
	private Texture texture;
	private float rotation_angle;
	private List<Point3D> animationPoints;
	private List<Float> animationTimes;
	private int curves;
	

	
	public Spaceship(List<Point3D> points, List<Float> times, int curves) {
		this.animationPoints = points;
		this.animationTimes = times;
		this.curves = curves;
		this.position = points.get(0);
		objLoader = new ObjLoader();
		model = objLoader.load(Gdx.files.internal("assets/models/Tardis.obj"), new ModelLoaderHints(true));
		texture = new Texture(Gdx.files.internal("assets/models/Tardis.jpg"));
	}
	
	public Point3D getPosition() {
		return this.position;
	}
	
	public void draw() {
		Gdx.gl11.glPushMatrix();
		Gdx.gl11.glTranslatef(position.x, position.y, position.z);
		Gdx.gl11.glRotatef(rotation_angle, 0, 1, 0);
		Gdx.gl11.glScalef(0.5f, 0.5f, 0.5f);
		Gdx.gl11.glEnable(GL11.GL_TEXTURE_2D);
		texture.bind();
		model.render();
		Gdx.gl11.glDisable(GL11.GL_TEXTURE_2D);
		Gdx.gl11.glPopMatrix();
	}
	
	public void update(float deltaTime, float elapsedTime) {
		this.rotation_angle += deltaTime * 100;
		calculatePosition(elapsedTime);
	}
	
	private void calculatePosition(float elapsedTime) {
		if (elapsedTime < animationTimes.get(0)){
			bezierCurve(animationPoints.get(0), animationPoints.get(1), animationPoints.get(2), animationPoints.get(3), elapsedTime/animationTimes.get(0));
		}
		else if (elapsedTime < animationTimes.get(1)) {
			float timeTheFinalFrontier = elapsedTime - animationTimes.get(0);
			bezierCurve(animationPoints.get(3), animationPoints.get(4), animationPoints.get(5), animationPoints.get(6), 
						timeTheFinalFrontier/(animationTimes.get(1) - animationTimes.get(0)));
		}
		else if (elapsedTime < animationTimes.get(2)) {
			float timeTheFinalFrontier = elapsedTime - animationTimes.get(1);
			bezierCurve(animationPoints.get(6), animationPoints.get(7), animationPoints.get(8), animationPoints.get(9), 
						timeTheFinalFrontier/(animationTimes.get(2) - animationTimes.get(1)));
		}
		else if (elapsedTime < animationTimes.get(3)) {
			float timeTheFinalFrontier = elapsedTime - animationTimes.get(2);
			bezierCurve(animationPoints.get(9), animationPoints.get(10), animationPoints.get(11), animationPoints.get(12), 
						timeTheFinalFrontier/(animationTimes.get(3) - animationTimes.get(2)));
		}
		else if (elapsedTime < animationTimes.get(4)) {
			float timeTheFinalFrontier = elapsedTime -animationTimes.get(3);
			bezierCurve(animationPoints.get(12), animationPoints.get(13), animationPoints.get(14), animationPoints.get(15), 
						timeTheFinalFrontier/(animationTimes.get(4) - animationTimes.get(3)));
		}
		else if (elapsedTime < animationTimes.get(5)) {
			float timeTheFinalFrontier = elapsedTime -animationTimes.get(4);
			bezierCurve(animationPoints.get(15), animationPoints.get(16), animationPoints.get(17), animationPoints.get(18), 
						timeTheFinalFrontier/(animationTimes.get(5) - animationTimes.get(4)));
		}
		else if (elapsedTime < animationTimes.get(6)) {
			float timeTheFinalFrontier = elapsedTime -animationTimes.get(5);
			bezierCurve(animationPoints.get(18), animationPoints.get(19), animationPoints.get(20), animationPoints.get(21), 
						timeTheFinalFrontier/(animationTimes.get(6) - animationTimes.get(5)));
		}
		
	}
	
	private void bezierCurve(Point3D start, Point3D c1, Point3D c2, Point3D end, float t) {
		float x = (float) (Math.pow((1 - t), 3) * start.x + 3 * Math.pow((1 - t), 2) * t * c1.x + 3 * (1 - t) * Math.pow(t ,2) * c2.x + Math.pow(t, 3) * end.x); 
		float y = (float) (Math.pow((1 - t), 3) * start.y + 3 * Math.pow((1 - t), 2) * t * c1.y + 3 * (1 - t) * Math.pow(t ,2) * c2.y + Math.pow(t, 3) * end.y);
		float z = (float) (Math.pow((1 - t), 3) * start.z + 3 * Math.pow((1 - t), 2) * t * c1.z + 3 * (1 - t) * Math.pow(t ,2) * c2.z + Math.pow(t, 3) * end.z);
		
		this.position.x = x;
		this.position.y = y;
		this.position.z = z;
	}
	
}
