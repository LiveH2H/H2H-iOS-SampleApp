//
//  H2HCollectionProtocol.h
//  H2H
//
//  Created by Sagar Kasture on 09/03/16.
//  Copyright © 2016 Sagar Kasture. All rights reserved.
//

#ifndef H2HCollectionProtocol_h
#define H2HCollectionProtocol_h

@protocol H2HCellToCollectionNotifyDelegate <NSObject>
@optional
/*!
 * @discussion This method is invoked when expand button is tapped in cell.
 * @param cell is the cell of which expand button has been tapped.
 */
-(void)cellExpandTapped:(UICollectionViewCell*)cell;
@end

@protocol H2HChildToCellNotifyDelegate <NSObject>
@optional
/*!
 * @discussion This method informs cell about any activity in it's child view controller
 * @param type is the type of activity which needs to be informed about to cell
 */
-(void) informCellWithActivityType:(CHILD_ACTIVITY_TYPE)type;
@end

@protocol H2HCollectionToCellChildNotifyDelegate <NSObject>
@optional
/*!
 * @discussion This method is called when child view of cell needs to be updated for layout update.
 * @param object contains information required by child view controller to layout appropriately.
 */
-(void)layoutUpdateWithObject:(NSObject*)object;

/*!
 * @discussion This method is called to set delegate to child view controller to inform to cell.
 * @param delegateObject is the delegate that needs to be given to child view controller.
 */
-(void) setChildToCellDelegate:(id<H2HChildToCellNotifyDelegate>)delegateObject;
@end

#endif /* H2HCollectionProtocol_h */
