/* Implement: Define each function of Sphere class */

void Sphere::draw() const {
	/* Implement: Draw sphere using glutSolidSphere(), glPushMatrix(), glPopMatrix() */

	// Material setting
	float mat_emission[] = { 0.3, 0.0, 0.0, 1.0 };
	float mat_ambient[] = { 1.0, 0.5, 0.2, 1.0 };
	float mat_diffuse[] = { 0.3, 0.5, 0.5, 1.0 };
	float mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	float mat_shininess[] = { 50 };

	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

}