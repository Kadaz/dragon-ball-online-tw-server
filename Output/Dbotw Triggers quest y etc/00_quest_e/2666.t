CNtlTSTrigger
{
	sm = 1;
	sq = 1;
	qc = 7;
	rq = 0;
	tid = 2666;
	title = 266602;

	CNtlTSGroup
	{
		gid = 0;

		CDboTSContGAct
		{
			cid = 2;
			elnk = 252;
			nextlnk = 100;
			prelnk = "1;";

			CDboTSActNPCConv
			{
				conv = 266609;
				ctype = 1;
				idx = 4652101;
				taid = 2;
			}
			CDboTSActRegQInfo
			{
				cont = 266608;
				gtype = 1;
				area = 266601;
				goal = 266604;
				grade = 132203;
				rwd = 100;
				scitem = -1;
				sort = 266605;
				stype = 2;
				taid = 1;
				title = 266602;
			}
		}
		CDboTSContReward
		{
			canclnk = 255;
			cid = 100;
			rwdzeny = 0;
			desc = 266614;
			nextlnk = 254;
			rwdexp = 0;
			rwdtbl = 266601;
			rwdtype = 0;
			ltime = -1;
			prelnk = "2;";
			usetbl = 1;

			CDboTSClickNPC
			{
				npcidx = "5553103;";
			}
		}
		CDboTSContGAct
		{
			cid = 252;
			elnk = 255;
			nextlnk = 253;
			prelnk = "2;";
		}
		CDboTSContProposal
		{
			cancellnk = 253;
			cid = 1;
			cont = 266608;
			gtype = 1;
			oklnk = 2;
			area = 266601;
			goal = 266604;
			sort = 266605;
			prelnk = "0;";
			ds = 1;
			grade = 132203;
			rwd = 100;
			title = 266602;
		}
		CDboTSContStart
		{
			cid = 0;
			stdiag = 266607;
			nolnk = 253;
			rm = 0;
			yeslnk = 1;

			CDboTSCheckLvl
			{
				maxlvl = 100;
				minlvl = 54;
			}
			CDboTSClickNPC
			{
				npcidx = "4652101;";
			}
			CDboTSCheckClrQst
			{
				and = "2665;";
				flink = 1;
				not = 0;
			}
		}
		CDboTSContEnd
		{
			cid = 253;
			prelnk = "0;1;252;";
			type = 0;
		}
		CDboTSContEnd
		{
			cid = 254;
			prelnk = "100;";
			type = 1;
		}
	}
}

