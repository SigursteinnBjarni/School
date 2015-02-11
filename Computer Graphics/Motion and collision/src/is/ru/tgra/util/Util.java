package is.ru.tgra.util;

/**
 * Util class for linear calculations
 * @author DrepAri
 *
 */
public class Util {
	
	/**
	 * Calculates time until ray hits the line B-C
	 * @param A Position of moving point
	 * @param B	Point on line
	 * @param C Point on line
	 * @param n Normal of line
	 * @return Time to hit
	 */
	public static float tHit(Point2D A, Point2D B, Vector2D C, Vector2D n) {
		float f2 = Util.dotProduct(C, n);
		
		if (f2 != 0) {
			Vector2D D = new Vector2D((B.getX() - A.getX()), (B.getY() - A.getY()));
			float f1 = Util.dotProduct(D, n);
			return f1/f2;
		}
		return -1;
		
	}
	
	/**
	 * Calculates the point on the line that gets hit
	 * @param A Point that is moving
	 * @param C Vector of line 
	 * @param tHit Time until impact
	 * @return Point of collision
	 */
	public static Point2D pHit(Point2D A, Vector2D C, float tHit) {
		return new Point2D((A.getX() + C.getX() * tHit), (A.getY() + C.getY() * tHit));
	}
	
	/**
	 * Returns the dotproduct of two vectors
	 * @param v1 First vector
	 * @param v2 Second vector
	 * @return Dot product
	 */
	public static float dotProduct(Vector2D v1, Vector2D v2) {
		return (v1.getX() * v2.getX() + v1.getY() * v2.getY());
	}
	
	/**
	 * Calculates normal of line given two points on it
	 * @param A First point
	 * @param B Second point
	 * @return Normal vector
	 */
	public static Vector2D normalVector(Point2D A, Point2D B) {
		return new Vector2D(-(B.getY() - A.getY()), (B.getX() - A.getX()));
	}
	
	/**
	 * Checks if point is on line segment
	 * @param A Point on line
	 * @param B Point on line
	 * @param C Point to check
	 * @return True if point is on line false otherwise
	 */
	public static boolean isBetween(Point2D A, Point2D B, Point2D C) {
		Vector2D D = new Vector2D(B.getX() - A.getX(), B.getY() - A.getY());
		Vector2D E = new Vector2D(C.getX() - A.getX(), C.getY() - A.getY());
		if (Math.abs(crossProduct(D, E)) > 1) {
			return false;
		}
		float dotproduct = dotProduct(D, E);
		if (dotproduct < 0) {
			return false;
		}
		if (dotproduct > (D.getX() * D.getX() + D.getY() * D.getY())) {
			return false;
		}
		
		return true;
	}
	
	/**
	 * Calculates the cross product of two vectors
	 * @param A First vector
	 * @param B Second vector
	 * @return The cross product of the vectors
	 */
	public static float crossProduct(Vector2D A, Vector2D B) {
		return (B.getY() * A.getX()) - (B.getX() * A.getY());
	}
	
	/**
	 * Calculates a response vector based on a normal
	 * @param a Original movement vector
	 * @param n normal of the line that the collision is happening on
	 * @return A new collision vector
	 */
	public static Vector2D collisionResponse(Vector2D a, Vector2D n) {
		n.normalize();
		float b = 2 * Util.dotProduct(a, n);
		Vector2D v = new Vector2D(n.getX() * b, n.getY() * b);
		
		return new Vector2D(a.getX() - v.getX(), a.getY() - v.getY());
	}

}
