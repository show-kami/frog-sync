library(animation)

num.frogs <- 100 # 考えている個体数
data <- read.csv("output_thetaForRasterPlot.csv", header = T)
num.timeslice <- nrow(data)

pb <- txtProgressBar(min = 1, max = num.timeslice, style = 3)

execute <- function(){
	for(i in 1:num.timeslice){
		plot(0,0, pch = 16, col = "white", xlim = c(0,10), ylim = c(0,10))

		for(x in 1:10){
			for(y in 1:10){
				par(new = T)
				pos = (x-1) + 10 * (y-1)
				if(data[i, pos+2] == -1){
					plot(x-1,y-1, pch = 16, cex = 3, col = "black", xlim = c(0,10), ylim = c(0,10))
				} else {
					plot(x-1,y-1, pch = 16, cex = 3, col = "red", xlim = c(0,10), ylim = c(0,10))
				}
			}
		}
		setTxtProgressBar(pb, i) 
	}
}

saveHTML(
	{
		execute()
	}, interval = 0.01, movie.name = "./phase_animation.gif"
)


