const Draw = () => {
    var canvas = document.getElementById("myCanvas");
    var ctx = canvas.getContext("2d");
    ctx.clearRect(0, 0, 1000, 500);
    let C = document.inputData.C.value*1;
    let E = document.inputData.E.value*1;
    let C_ratio = C / 36;
    let E_ratio = E / 163;
    let sizeMugnitude = 3;

    let centralRectWidth = 45 * E_ratio * sizeMugnitude;
    let centralRectHeight = 48 * sizeMugnitude;

    let leftCentralRectWidth = 82 * E_ratio * sizeMugnitude;
    let leftCentralRectHeight = 36 * C_ratio * sizeMugnitude;

    let leftBorderRectWidth = (36 * E_ratio * sizeMugnitude) - Math.sqrt(2)*sizeMugnitude;
    let leftBorderRectHeight = 30 * sizeMugnitude;

    let rightCentralNarrowRectWidth = 3 * sizeMugnitude;
    let rightCentralNarrowRectHeight = 43 * sizeMugnitude;

    let rightCentralNarrowAngledRectWidth = (7 * sizeMugnitude) - Math.sqrt(2)*sizeMugnitude;
    let rightCentralNarrowAngledRectHeight = 52  * sizeMugnitude;

    let rightCentralRectWidth = 70 * sizeMugnitude;
    let rightCentralRectHeight = 36 * sizeMugnitude;
    let rightCentralRectOffset = centralRectWidth/2 + rightCentralNarrowRectWidth + rightCentralNarrowAngledRectWidth + Math.sqrt(2)*sizeMugnitude

    let rightBorderNarrowRectWidth = 2 * sizeMugnitude;
    let rightBorderNarrowRectHeight = 25 * sizeMugnitude;
    let rightBorderNarrowRectOffset = rightCentralRectOffset + rightCentralRectWidth;

    let rightBorderAngledRectWidth = (12 * sizeMugnitude) - Math.sqrt(2)*sizeMugnitude;
    let rightBorderAngledRectHeight = 30 * sizeMugnitude;
    let rightBorderAngledRectOffset = rightBorderNarrowRectOffset + rightBorderNarrowRectWidth;

    DrawAxialLine(ctx);
    DrawCentralRectangle(ctx, centralRectWidth, centralRectHeight);
    DrawLeftCentralRectangle(ctx, leftCentralRectWidth, leftCentralRectHeight, centralRectWidth);
    DrawLeftBorderSquare(ctx, leftBorderRectWidth, leftBorderRectHeight, leftCentralRectWidth + centralRectWidth/2, sizeMugnitude);
    DrawRightCentralNarrowRect(ctx, rightCentralNarrowRectWidth, rightCentralNarrowRectHeight, centralRectWidth);
    DrawRightCentralNarrowAngledRect(ctx, rightCentralNarrowAngledRectWidth, rightCentralNarrowAngledRectHeight, rightCentralNarrowRectWidth + centralRectWidth/2, sizeMugnitude);
    DrawRightCentralRect(ctx, rightCentralRectWidth, rightCentralRectHeight, rightCentralRectOffset);
    DrawRightBorderNarrowRect(ctx, rightBorderNarrowRectWidth, rightBorderNarrowRectHeight, rightBorderNarrowRectOffset);
    DrawRightBorderAngledRect(ctx, rightBorderAngledRectWidth, rightBorderAngledRectHeight, rightBorderAngledRectOffset, sizeMugnitude);
}

const DrawAxialLine = (ctx) => {
    ctx.save();
    ctx.beginPath();
    ctx.setLineDash([50, 20, 2, 20]);
    ctx.moveTo(0, 250);
    ctx.lineTo(1000, 250);
    ctx.stroke();
    ctx.closePath();
    ctx.restore();
}

const DrawCentralRectangle = (ctx, rectWidth, rectHeight) => {
    let x = 500 - rectWidth/2;
    let y = 250 - rectHeight/2;
    ctx.moveTo(x, y) //initial position
    let direction = 1; //1 -> right ----  -1 -> left
    DrawRectangle(ctx, x, y, rectWidth, rectHeight, direction);
}

const DrawLeftCentralRectangle = (ctx, rectWidth, rectHeight, centralRectWidth) => {
    let x = 500 - centralRectWidth/2;
    let y = 250 - rectHeight/2;
    let direction = -1; //1 -> right ----  -1 -> left
    DrawRectangle(ctx, x, y, rectWidth, rectHeight, direction);
}

const DrawLeftBorderSquare = (ctx, rectWidth, rectHeight, xOffset, sizeMagnitude) => {
    let x = 500 - xOffset;
    let y = 250 - rectHeight/2;
    let direction = -1; //1 -> right ----  -1 -> left
    DrawRectangle(ctx, x, y, rectWidth, rectHeight, direction);

    x = 500 - xOffset - rectWidth;
    y = 250 - rectHeight/2;
    let smallHeight = rectHeight - 2 * (Math.sqrt(2) * sizeMagnitude);
    DrawAngledRectangle(ctx, x, y, smallHeight, sizeMagnitude, direction);
}

const DrawRightCentralNarrowRect = (ctx, rectWidth, rectHeight, centralRectWidth) => {
    let x = 500 + centralRectWidth/2;
    let y = 250 - rectHeight/2;
    let direction = 1; //1 -> right ----  -1 -> left
    DrawRectangle(ctx, x, y, rectWidth, rectHeight, direction);
}

const DrawRightCentralNarrowAngledRect = (ctx, rectWidth, rectHeight, xOffset, sizeMagnitude) => {
    let x = 500 + xOffset;
    let y = 250 - rectHeight/2;
    let direction = 1; //1 -> right ----  -1 -> left
    DrawRectangle(ctx, x, y, rectWidth, rectHeight, direction);

    x = 500 + xOffset + rectWidth;
    y = 250 - rectHeight/2;
    let smallHeight = rectHeight - 2 * (Math.sqrt(2) * sizeMagnitude);
    DrawAngledRectangle(ctx, x, y, smallHeight, sizeMagnitude, direction);
}

const DrawRightCentralRect = (ctx, rectWidth, rectHeight, xOffset) => {
    let x = 500 + xOffset;
    let y = 250 - rectHeight/2;
    let direction = 1; //1 -> right ----  -1 -> left
    DrawRectangle(ctx, x, y, rectWidth, rectHeight, direction);
}

const DrawRightBorderNarrowRect = (ctx, rectWidth, rectHeight, xOffset) => {
    let x = 500 + xOffset;
    let y = 250 - rectHeight/2;
    let direction = 1; //1 -> right ----  -1 -> left
    DrawRectangle(ctx, x, y, rectWidth, rectHeight, direction);
}

const DrawRightBorderAngledRect = (ctx, rectWidth, rectHeight, xOffset, sizeMagnitude) => {
    let x = 500 + xOffset;
    let y = 250 -  rectHeight/2;
    let direction = 1; //1 -> right ----  -1 -> left
    DrawRectangle(ctx, x, y, rectWidth, rectHeight, direction);

    x = 500 + xOffset + rectWidth;
    y = 250 - rectHeight/2;
    let smallHeight = rectHeight - 2 * (Math.sqrt(2) * sizeMagnitude);
    DrawAngledRectangle(ctx, x, y, smallHeight, sizeMagnitude, direction);
}

const DrawRectangle = (ctx, x, y, rectWidth, rectHeight, direction) => {
    ctx.save();
    ctx.beginPath();
    ctx.moveTo(x, y);

    x = x + (rectWidth * direction);
    ctx.lineTo(x, y);
    y = y + rectHeight;
    ctx.lineTo(x, y);
    x = x - (rectWidth * direction);
    ctx.lineTo(x, y);
    y = y - rectHeight;
    ctx.lineTo(x, y);

    ctx.stroke();
    ctx.closePath();
    ctx.restore();
}

const DrawAngledRectangle = (ctx, x, y, smallHeight, sizeMagnitude, direction) => {
    ctx.save();
    ctx.beginPath();
    ctx.moveTo(x,y);

    x = x + (Math.sqrt(2) * sizeMagnitude * direction);
    y = y + Math.sqrt(2) * sizeMagnitude;
    ctx.lineTo(x, y);
    y = y + smallHeight;
    ctx.lineTo(x, y);
    x = x - (Math.sqrt(2) * sizeMagnitude * direction);
    y = y + Math.sqrt(2) * sizeMagnitude;
    ctx.lineTo(x, y);

    ctx.stroke();
    ctx.closePath();
    ctx.restore();
}

const SetDefaultValues = () => {
    document.inputData.C.value = 36;
    document.inputData.E.value = 163;
    document.inputData.Cslider.value = 36;
    document.inputData.Eslider.value = 163;
    Draw();
}

const changeCvalue = () => {
    let C = document.inputData.Cslider.value*1;
    document.inputData.C.value = C;
    Draw();
}

const changeEvalue = () => {
    let E = document.inputData.Eslider.value*1;
    document.inputData.E.value = E;
    Draw();
}

const ClearCanvas = () => {
    var canvas = document.getElementById("myCanvas");
    var ctx = canvas.getContext("2d");
    ctx.clearRect(0, 0, 1000, 500);
}