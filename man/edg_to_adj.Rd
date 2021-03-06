% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/graph.R
\name{edg_to_adj}
\alias{edg_to_adj}
\title{Edge list to adjacency matrix}
\usage{
edg_to_adj(edg, weight = NULL, directed = FALSE, adjlist = FALSE)
}
\arguments{
\item{edg}{character matrix with two columns containing the from and to
nodes of the edges.}

\item{weight}{optional numeric vector specifiying the weights associated with
each edge.}

\item{directed}{logical specifying whether edges should only be included
for from-to or also fro to-from.}

\item{adjlist}{logical specifying whether to export the adjancy matrix as an
\code{adjlist} as required by \link{fluency}.}
}
\value{
a numeric n x n adjacency matrix with n being the number of unique
  entries in \code{edg}.
}
\description{
Transforms an edge list as returned by \link{community_graph} into an
adjacency matrix or \code{adjlist}.
}
\examples{

# get fluency data
data(animal_fluency)

# edge list of fluency graph
edge_list = threshold_graph(animal_fluency[1:3])

# transfrom to adjacency matrix
edg_to_adj(edge_list)

}
