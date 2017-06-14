import {
  Component,
  Input,
  OnInit,
  OnDestroy,
} from '@angular/core';

import {
  YogiService,
} from '../../core/core.module';

import {
  ReceivedRegularMessage,
  ScatterGatherReply,
} from '../terminal-control/terminal-control.component';

@Component({
  selector: 'ce-terminal',
  templateUrl: 'terminal.component.html',
  styleUrls: ['terminal.component.css']
})
export class TerminalComponent implements OnInit, OnDestroy {
  @Input() terminalType: any;
  @Input() terminalName: string;
  @Input() signature: yogi.Signature;
  @Input() canSend: boolean = true;
  @Input() canReceive: boolean = true;
  @Input() hidden: boolean = false;

  public bound = false;
  public subscribed = false;

  private terminal: yogi.Terminal;
  private binding: yogi.Binding = null;
  private lastReceivedRegularMessage: ReceivedRegularMessage; // regular = (Cached) PS, Master or Slave Message
  private lastReceivedScatterMessage: yogi.ScatterMessage;
  private lastReceivedGatherMessage: yogi.GatherMessage;
  private lastScatterOperation: yogi.Operation;
  private scatterGatherReply: ScatterGatherReply;

  constructor(private yogiService: YogiService) {
  }

  ngOnInit() {
    this.terminal = new this.terminalType(this.yogiService.session, this.terminalName,
      this.signature);

    if (this.canReceive && this.terminal instanceof yogi.PrimitiveTerminal) {
      this.binding = new yogi.Binding(this.terminal, this.terminalName);
    }

    if ('onMessageReceived' in this.terminal) {
      (this.terminal as any).onMessageReceived = (msg: yogi.Message, cached?: boolean) => {
        this.onRegularMessageReceived(msg, cached);
      };
    }
    else if ('onScatterMessageReceived' in this.terminal) {
      (this.terminal as any).onScatterMessageReceived = (msg: yogi.ScatterMessage) => {
        this.onScatterMessageReceived(msg);
      };
    }

    if ('onSubscriptionStateChanged' in this.terminal) {
      (this.terminal as any).onSubscriptionStateChanged = (subscribed: boolean) => {
        this.subscribed = subscribed;
      };
    }

    if ('onBindingStateChanged' in this.terminal) {
      (this.terminal as any).onBindingStateChanged = (established: boolean) => {
        this.bound = established;
      };
    }
    else if (this.binding) {
      this.binding.onBindingStateChanged = (established: boolean) => {
        this.bound = established;
      };
    }
  }

  ngOnDestroy() {
    if (this.binding) {
      this.binding.destroy();
    }

    this.terminal.destroy();
  }

  onRegularMessageReceived(msg: yogi.Message, cached?: boolean) {
    this.lastReceivedRegularMessage = {
      msg: msg,
      cached: !!cached
    };
  }

  onScatterMessageReceived(msg: yogi.ScatterMessage) {
    this.lastReceivedScatterMessage = msg;
    if (this.scatterGatherReply && !this.scatterGatherReply.ignore) {
      msg.respond(this.scatterGatherReply.msg as yogi.Message); // TODO: what about custom Terminals?
    }
    else {
      msg.ignore();
    }
  }

  sendRegularMessage(msg: yogi.Message) {
    (this.terminal as any).publish(msg);
  }

  sendScatterMessage(msg: yogi.Message) {
    let fn = (gatherMsg: yogi.GatherMessage) => {
      if (gatherMsg.message && gatherMsg.operation.id === this.lastScatterOperation.id) {
        this.lastReceivedGatherMessage = gatherMsg;
      }
    };

    if ('scatterGather' in this.terminal) {
      this.lastScatterOperation = (this.terminal as any).scatterGather(msg, fn);
    }
    else {
      this.lastScatterOperation = (this.terminal as any).request(msg, fn);
    }
  }

  onScatterGatherReplyChanged(reply: ScatterGatherReply) {
    this.scatterGatherReply = reply;
  }
}
