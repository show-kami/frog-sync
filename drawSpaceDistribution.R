library(animation)

num.frogs <- 100 # 考えている個体数
data <- read.csv("output_thetaForRasterPlot.csv", header = T)
num.timeslice <- nrow(data)

pb <- txtProgressBar(min = 1, max = num.timeslice, style = 3)

execute <- function(){
	for(i in 1:num.timeslice){
		plot(0,0,type = "n", xlim = c(0,10), ylim = c(0,10))

		for(x in 1:10){
			for(y in 1:10){
				pos = (x-1) + 10 * (y-1)
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
	ani.options(interval = 0.01)
	execute()
},video.name = "anime_space.mp4", other.opts = "-pix_fmt yuv420p -b 1000k"
)
