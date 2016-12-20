library(animation)

koushi <- 6 # 格子間隔

num.frogs <- 100 # 考えている個体数
num.array <- sqrt(num.frogs)
data <- read.csv("output_thetaForRasterPlot.csv", header = T)
num.timeslice <- nrow(data)

pb <- txtProgressBar(min = 1, max = num.timeslice, style = 3)

execute <- function(){
	for(i in 1:num.timeslice){
		plot(0,0,type = "n", xlim = c(0,num.array), ylim = c(0,num.array), xlab = "x [m]", ylab = "y[m]", xaxt = "n", yaxt = "n")
		axis.point <- 0:num.array
		axis.name <- c(as.character(axis.point * koushi))
		axis(1, at = axis.point, labels = axis.name)
		axis(2, at = axis.point, labels = axis.name)

		for(x in 1:num.array){
			for(y in 1:num.array){
				pos = (x-1) + num.array * (y-1)
				if(data[i, pos+2] != -1){
					points(x-1,y-1, pch = 16, cex = 3, col = "red")
				}
			}
		}

		setTxtProgressBar(pb, i)
	}
}

# saveHTML(
# 	{
# 		execute()
# 	}, interval = 0.01, movie.name = "./phase_animation.gif"
# )

saveVideo({
	ani.options(interval = 0.05)
	execute()
},video.name = "anime_space.mp4", other.opts = "-pix_fmt yuv420p -b 1000k"
)
#saveVideoのビデオの大きさを変えるやり方ってないのかな？