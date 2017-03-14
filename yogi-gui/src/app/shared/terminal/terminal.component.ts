import {
  Component,
  Input,
  OnInit,
  OnDestroy,
} from '@angular/core';

import {
  YogiService,
} from '../../core/core.module';

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
  private lastReceivedPublishMessage: yogi.Message;
  private lastReceivedCachedPublishMessage: yogi.Message;
  private lastReceivedScatterMessage: yogi.ScatterMessage;
  private lastReceivedGatherMessage: yogi.GatherMessage;

  constructor(private YogiService: YogiService) {
  }

  ngOnInit() {
    this.terminal = new this.terminalType(this.YogiService.session, this.terminalName,
      this.signature);

    if (this.canReceive && this.terminal instanceof yogi.PrimitiveTerminal) {
      this.binding = new yogi.Binding(this.terminal, this.terminalName);
    }

    if ('onMessageReceived' in this.terminal) {
      (this.terminal as any).onMessageReceived = (msg: yogi.Message, cached: boolean) => {
        this.onPublishMessageReceived(msg, cached);
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

  onPublishMessageReceived(msg: yogi.Message, cached?: boolean) {
    if (cached) {
      this.lastReceivedCachedPublishMessage = msg;
    }
    else {
      this.lastReceivedPublishMessage = msg;
    }
  }

  onScatterMessageReceived(msg: yogi.ScatterMessage) {
    this.lastReceivedScatterMessage = msg;
  }

  sendPublishMessage(msg: yogi.Message) {
    (this.terminal as any).publish(msg);
  }
}
