/*
 * JOOSJ is Copyright (C) 2000 Othman Alaoui
 *
 * Reproduction of all or part of this software is permitted for
 * educational or research use on condition that this copyright notice is
 * included in any copy. This software comes with no warranty of any
 * kind. In no event will the author be liable for any damages resulting from
 * use of this software.
 *
 * email: oalaou@po-box.mcgill.ca
 */


package joosc.resource;

/*
 * AndExpLabels
 *
 * Provides the labels necessary to generate code 
 * for an and expression.
 *
 * History:
 *   25 May 2000 - created
 */
public class AndExpLabels extends Labels {
	private int falseLabel;
	
	public AndExpLabels(int falseLabel) {
		this.falseLabel = falseLabel;
	}
	
	public int getFalseLabel() { return falseLabel; }
}