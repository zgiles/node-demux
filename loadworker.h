#ifndef LOADWORKER_H
#define LOADWORKER_H

#include <string>
#include <node.h>
#include <nan.h>
#include "demuxbaton.h"
#include "demuxworker.h"
#include "seekworker.h"

class LoadWorker : public Nan::AsyncWorker {
	public:
		LoadWorker(DemuxBaton *btn, std::string fn, bool dff)
			: Nan::AsyncWorker(NULL), baton(btn), filename(fn), decodeFirstFrame(dff) {};
		~LoadWorker() {};
		
		void Execute();
		void HandleOKCallback();
		
	private:
		DemuxBaton *baton;
		std::string filename;
		bool decodeFirstFrame;
};

#endif // LOADWORKER_H